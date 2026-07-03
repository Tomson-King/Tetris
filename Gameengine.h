struct shapes;
void game();
int rand_shape();
void get_cursor(int shape,struct shapes cursor);
void set_board();
void print_board();
struct shapes rotate(struct shapes cursor);
void check_board(struct shapes cursor);
void update_board(struct shapes cursor);