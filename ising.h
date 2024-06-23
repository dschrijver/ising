#ifndef ISING_H
#define ISING_H

#define SCREEN_WIDTH_INI    (int) 1280
#define SCREEN_HEIGHT_INI   (int) 720
#define CELL_SIZE_INI       (int) 5                 // [pixels/cell]
#define FPS              (double) 60.0              // [1/s]
#define EVO_FREQ_INI        (int) 2000*((int)FPS)   // [evolutions/s]

const double    mu_b = 9.274e-24;
const double     k_b = 1.380649e-23;
double T, J, H;

int screen_width = SCREEN_WIDTH_INI, screen_height = SCREEN_HEIGHT_INI;
int cell_size = CELL_SIZE_INI;
int num_cells_x, num_cells_y, margin_x, margin_y;

int mod_neg(int x, int y);
void update_grid_size();
double delta_E(unsigned int i, unsigned int j, int grid[num_cells_x][num_cells_y]);
double p(double del_E);
void evolve_spins(int grid[num_cells_x][num_cells_y]);

#endif