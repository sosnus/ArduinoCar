#define SERIAL_BAUD 57600
// #define SERIAL_DELAY    2000

class Dbg
{
  public:
    Dbg(); //include init
    int checkCmd();
    void dioda();
    void led(int state);

    void initialisation();
    int sendVariable(int varName);
    // int setVariable(int varName);

  private:
    int potentiometer=222;
    bool state = false;
};

// void dioda(){