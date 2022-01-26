#include <cstdlib>
#include "direction.h"

Direction random_direction() {
    return static_cast<Direction>(rand() % DOWN);
}
