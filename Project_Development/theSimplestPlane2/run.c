#include "planeFunctions.h"

int main() {
    startup();
    while (1) {
        show();
        updateWithoutInput();
        updateWithInput();
    }
    return 0;
}