#include <cmath>
#include <vector>
#include <framework.h>

int main(int argc, char * argv[]){

    // Creating the object by passing Height and Width value.
    Framework* fw = new Framework(600, 800);

    int exitCode = fw->run();

    return exitCode;
}