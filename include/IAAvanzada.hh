#ifndef IAAVANZADA_HH
#define IAAVANZADA_HH
#include <IJugador.hh>
#include <string>

using namespace std;

class IAAvanzada : public IJugador{
    public:
    IAAvanzada(int maxDepth);
    int movimientoIA();
    int maxDepth;
};
#endif