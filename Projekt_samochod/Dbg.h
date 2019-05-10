#define SERIAL_BAUD 57600
// #define SERIAL_DELAY    2000

class Dbg
{
  public:
    //Dbg(); //include init
    static int checkCmd();
    static void dioda();
    static void drukuj();
    static void led(int state);

    static void initialisation();
    static int sendVariable(int varName);
    // int setVariable(int varName);

    static String content;
    static void change();
  static void setContent(String s);


  private:
    static int potentiometer;
    static bool state;
};


// class Dbg
// {
//   public:
//     Dbg(); //include init
//     int checkCmd();
//     void dioda();
//     void drukuj();
//     void led(int state);

//     void initialisation();
//     int sendVariable(int varName);
//     // int setVariable(int varName);

//   private:
//     int potentiometer=222;
//     bool state = false;
// };

// void dioda(){