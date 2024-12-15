#include <iostream>
#include <string>
#include <vector>

std::vector<int> split_line(std::string line) {
  std::vector<int> res;
  int num = 0;
  for (int i = 0; i < line.size(); ++i) {
    if (line[i] == ' ') {
      res.push_back(num);
      num = 0;
    } else {
      num = 10 * num + (line[i] - '0');
    }
  }
  res.push_back(num);
  return res;
}

bool check_if_safe(std::vector<int> report) {
  int decr, incr, diff, safe_diff;
  decr = incr = safe_diff = 1;
  for (int i = 0; i < report.size() - 1; ++i) {
    diff = std::abs(report[i + 1] - report[i]);
    incr = incr && (report[i + 1] > report[i]);
    decr = decr && (report[i + 1] < report[i]);
    safe_diff = safe_diff && (diff >= 1 && diff <= 3);
    if (!((decr || incr) && safe_diff))
      return false;
  }
  return true;
}

FILE *stream;
int main() {
  freopen_s(&stream, "input", "r", stdin);
  freopen_s(&stream, "output1", "w", stdout);

  std::vector<std::vector<int>> reports;

  std::string line;
  while (std::getline(std::cin, line)) {
    std::vector<int> report = split_line(line);
    reports.push_back(report);
  }
  int ans = 0;
  for (std::vector<int> report : reports) {
    if (check_if_safe(report) == true)
      ++ans;
  }
  std::cout << ans << std::endl;
}
