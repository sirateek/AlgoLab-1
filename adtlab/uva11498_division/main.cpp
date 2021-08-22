#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int k;
  int coords[1000][1000][2];
  int division_points[1000][2];
  int k_size_per_coords[1000];
  int coord_position = 0;

  while (true) {
    cin >> k;
    if (k == 0) {
      break;
    }
    int division_point_x_input,division_point_y_input;
    cin >> division_point_x_input >> division_point_y_input;
    division_points[coord_position][0] = division_point_x_input;
    division_points[coord_position][1] = division_point_y_input;
    k_size_per_coords[coord_position] = k;
    int center_coord_x, center_coord_y;
    for (int i=0; i<k; i++) {
      cin >> center_coord_x >> center_coord_y;
      coords[coord_position][i][0] = center_coord_x;
      coords[coord_position][i][1] = center_coord_y;
    }
    coord_position++;
  };

  for (int i=0;i<coord_position; i++) {
    for (int k=0;k<k_size_per_coords[i];k++) {
      int position_x = coords[i][k][0];
      int position_y = coords[i][k][1];
      int division_point_x,division_point_y;
      division_point_x = division_points[i][0];
      division_point_y = division_points[i][1];
      if (position_x == division_point_x || position_y == division_point_y) {
        cout << "divisa";
      } else if (position_x > division_point_x && position_y > division_point_y) {
        cout << "NE";
      } else if (position_x < division_point_x && position_y > division_point_y) {
        cout << "NO";
      } else if (position_x > division_point_x && position_y < division_point_y) {
        cout << "SE";
      } else if (position_x < division_point_x && position_y < division_point_y) {
        cout << "SO";
      }
      cout << "\n";
    }
  }
  return 0;
}
