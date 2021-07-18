class Multiplexer
{

public:
    Multiplexer(int ctrlPin1,
                int ctrlPin2,
                int ctrlPin3,
                int ctrlPin4,
                int analogReadPin);

    ~Multiplexer();

    void begin();

    int readChannel(int channel);

private:

    int _ctrlPin1;
    int _ctrlPin2;
    int _ctrlPin3;
    int _ctrlPin4;

    int _analogReadPin;
};

