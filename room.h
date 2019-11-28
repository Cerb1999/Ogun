class Room {
public:
 Room(int t);
 int layout();
 void clear();
 void enter();
 bool cleared();
 bool occupied();
 int index();
 
private:
  int r_layout;
  int r_type;
  bool r_occupied;
  int r_cleared;
  int r_index;
};
