#pragma once

/*----------------------------------------------------------------
Definitions for returns:
    1. Absolute = (Current - Previous)

    2. Relative = log(Current / Previous)

See TSHandler.cpp for details and implementation
*/
enum class AbsOrRel { abs, rel };