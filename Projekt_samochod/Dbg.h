#define SERIAL_BAUD 57600

class Dbg
{
  public:
    Dbg(); //include init
    void initialisation();
    int getY();
    int life = 3;

  private:
    int x = 0;
    int y = 0;

    const int border_x_left = 0;
};