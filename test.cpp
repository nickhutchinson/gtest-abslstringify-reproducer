#include <absl/strings/str_format.h>
#include <gtest/gtest.h>

struct Point {
  Point(int x, int y) : x(x), y(y) {}

  template <typename Sink>
  friend void AbslStringify(Sink& sink, const Point& point) {
    absl::Format(&sink, "(%d, %d)", point.x, point.y);
  }

  int x{};
  int y{};

};

TEST(MyTest, PrintsViaGtest) {
  EXPECT_EQ(testing::PrintToString(Point(1, 2)), "(1, 2)");
}

TEST(MyTest, PrintsViaAbsl) {
  EXPECT_EQ(absl::StrCat(Point(1, 2)), "(1, 2)");
}

