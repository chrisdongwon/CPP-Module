#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

class FordJohnson {
 public:
  // Returns a new vector containing `input`'s elements in ascending order.
  static std::vector<int> sort(const std::vector<int>& input) {
    arr = input;

    std::vector<int> indices(arr.size());
    for (size_t i = 0; i < arr.size(); ++i) indices[i] = static_cast<int>(i);

    std::vector<int> sortedIdx = sortIndices(indices);

    std::vector<int> result;
    result.reserve(arr.size());
    for (int idx : sortedIdx) result.push_back(arr[idx]);
    return result;
  }

 private:
  static std::vector<int> arr;

  // The only place actual "did the algorithm need to look at two
  // elements" comparisons happen. Position bookkeeping below never
  // calls this.
  static bool less(int idxA, int idxB) {
    return arr[idxA] < arr[idxB];
  }

  // 1-indexed insertion order for pend ranks 2..k, via Jacobsthal numbers.
  // e.g. k=11 -> [3,2,5,4,11,10,9,8,7,6]
  static std::vector<size_t> insertionOrder(size_t k) {
    std::vector<size_t> order;
    if (k < 2)
      return order;

    std::vector<long long> jac = {1, 1};  // J(1), J(2)
    size_t prevJ = 1;
    size_t m = 2;

    while (prevJ < k) {
      if (m + 1 > jac.size()) {
        long long next = jac[jac.size() - 1] + 2 * jac[jac.size() - 2];
        jac.push_back(next);
      }
      ++m;
      size_t curJ = static_cast<size_t>(jac[m - 1]);
      size_t top = std::min(curJ, k);
      for (size_t r = top; r > prevJ; --r) order.push_back(r);
      prevJ = top;
    }
    return order;
  }

  // Sorts a list of indices (into `arr`) using merge-insertion sort.
  // Fully self-contained: the returned list is completely sorted.
  static std::vector<int> sortIndices(std::vector<int> indices) {
    size_t n = indices.size();
    if (n <= 1)
      return indices;

    std::vector<int> mains, pends;
    mains.reserve(n / 2);
    pends.reserve(n / 2);

    bool hasStraggler = (n % 2 == 1);
    int straggler = hasStraggler ? indices.back() : -1;

    for (size_t i = 0; i + 1 < n; i += 2) {
      int a = indices[i], b = indices[i + 1];
      if (less(a, b))
        std::swap(a, b);  // a = larger (main), b = smaller (pend)
      mains.push_back(a);
      pends.push_back(b);
    }

    std::unordered_map<int, int> mainToPend;
    mainToPend.reserve(mains.size() * 2);
    for (size_t i = 0; i < mains.size(); ++i) mainToPend[mains[i]] = pends[i];

    // Recursion does the heavy lifting: mains come back fully sorted.
    std::vector<int> sortedMains = sortIndices(mains);

    // Chain position of each index, kept in sync on every insert.
    // (Sized to the full array for simplicity -- fine for typical
    // input sizes; a hash map keyed by the live index set would be
    // more memory-frugal for very large n.)
    std::vector<int> pos(arr.size(), -1);

    std::vector<int> chain;
    chain.reserve(n);

    // b1 (pend of the smallest main) is guaranteed smaller than
    // everything placed so far -- no comparison needed to place it.
    int b1 = mainToPend[sortedMains[0]];
    chain.push_back(b1);
    pos[b1] = 0;
    for (int m : sortedMains) {
      chain.push_back(m);
      pos[m] = static_cast<int>(chain.size()) - 1;
    }

    auto insertAt = [&](int idxToInsert, size_t at) {
      chain.insert(chain.begin() + at, idxToInsert);
      for (size_t p = at; p < chain.size(); ++p)
        pos[chain[p]] = static_cast<int>(p);
    };

    // Binary-search insert into chain[0, bound), keeping chain sorted.
    auto insertBounded = [&](int idxToInsert, size_t bound) {
      size_t lo = 0, hi = bound;
      while (lo < hi) {
        size_t mid = lo + (hi - lo) / 2;
        if (less(chain[mid], idxToInsert))
          lo = mid + 1;
        else
          hi = mid;
      }
      insertAt(idxToInsert, lo);
    };

    // Insert b2..bk in Jacobsthal order. The bound for each pend is
    // its own main's *current* chain position -- pure bookkeeping,
    // not a comparison.
    size_t k = sortedMains.size();
    for (size_t rank : insertionOrder(k)) {
      int mainIdx = sortedMains[rank - 1];
      int pendIdx = mainToPend[mainIdx];
      size_t bound = static_cast<size_t>(pos[mainIdx]);
      insertBounded(pendIdx, bound);
    }

    if (hasStraggler)
      insertBounded(straggler, chain.size());

    return chain;
  }
};

std::vector<int> FordJohnson::arr;

int main() {
  std::vector<int> data = {8, 3, 15, 1, 9,  4, 12, 7,
                           0, 6, 11, 2, 14, 5, 10, 13};

  std::vector<int> sorted = FordJohnson::sort(data);

  std::cout << "Input:  ";
  for (int v : data) std::cout << v << " ";
  std::cout << "\nSorted: ";
  for (int v : sorted) std::cout << v << " ";

  // Sanity check
  std::vector<int> expected = data;
  std::sort(expected.begin(), expected.end());
  std::cout << "Correct: " << (sorted == expected ? "yes" : "NO") << "\n";

  return 0;
}
