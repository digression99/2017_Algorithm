#include <vector>
#include <iostream>
#include <bitset>
using namespace std;

class NumberMagicEasy {
public:
    bitset<16> cards[8]; // = {bitset<16>(0xFF00), 0x00FF, 0xF0F0, 0x0F0F, 0xCCCC, 0x3333, 0xAAAA, 0x5555};
    
    void init()
    {
        cards[0] = 0xFF00;
        cards[1] = 0x00FF;
        cards[2] = 0xF0F0;
        cards[3] = 0x0F0F;
        cards[4] = 0xCCCC;
        cards[5] = 0x3333;
        cards[6] = 0xAAAA;
        cards[7] = 0x5555;
        //for (int i = 1; i < 8; i += 2) cards[i] = cards[i - 1].flip();
    }
    
    int theNumber(string answer) {
        init();
        bitset<16> res = 0xFFFF;
        
        for (int i = 0; i < 8; ++i) cout << cards[i] << endl;
        //cout << "CARDS" << endl;
        
        for (int i = 0; i < 4; ++i)
        {
            if (answer[i] == 'Y')
                res &= cards[i * 2];
            else res &= cards[i * 2 + 1];
            //cout << res << endl;
        }
        
        //cout << res << endl;
        for (int i = 0; i < 16; ++i) if (res[i]) return 16 - i;
        return -1;
    }
};

int main()
{
    NumberMagicEasy obj = NumberMagicEasy();
    cout << obj.theNumber("YNYY") << endl;
    
    
    return 0;
}
