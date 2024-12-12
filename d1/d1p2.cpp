#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <vector>

FILE *stream;
int main() {
  freopen_s(&stream, "input", "r", stdin);
  freopen_s(&stream, "output2", "w", stdout);

  std::vector<int> left_list;
  std::unordered_map<int, int> right_mp;

  int left_int, right_int;

  while (std::cin >> left_int >> right_int) {
    left_list.push_back(left_int);
    if (right_mp.count(right_int))
      ++right_mp[right_int];
    else
      right_mp[right_int] = 1;
  }

  long long ans = 0;
  for (int left_int : left_list) {
    if (right_mp.count(left_int))
      ans += left_int * right_mp[left_int];
  }

  std::cout << ans << std::endl;

  return 0;
}
