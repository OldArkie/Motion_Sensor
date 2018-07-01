//--------------------------------------------------------------------------
// Encapsulates SendOnlySoftwareSerial as a singleton.
//--------------------------------------------------------------------------
#ifndef MSSerial_h
#define MSSerial_h

#include <SendOnlySoftwareSerial.h>

class MSSerial : public SendOnlySoftwareSerial
{
    public: 
        inline static MSSerial& getInstance(int pin=-1)
        {
            static MSSerial instance(pin); // Guaranteed to be destroyed.
                                           // Instantiated on first use.
            return instance;
        }
        
    private:
        MSSerial(uint8_t transmitPin) : SendOnlySoftwareSerial(transmitPin)
        {
        }

    public:
        MSSerial(MSSerial const&)        = delete;
        void operator=(MSSerial const&)  = delete;

        // Note: Scott Meyers mentions in his Effective Modern
        //       C++ book, that deleted functions should generally
        //       be public as it results in better error messages
        //       due to the compilers behavior to check accessibility
        //       before deleted status
};

#endif
