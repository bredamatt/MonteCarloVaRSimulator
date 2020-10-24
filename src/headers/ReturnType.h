#pragma once

/*----------------------------------------------------------------
Definitions for returns:
   1. Absolute = (Current - Investment) / Investment
    
        Absolute return example:
            Investment = £8,000
            Current value = £10,000

        Absolute return Y2 to Y1 = (10,000-8,000) / 8,000 = 25%


    2. Relative = (Current - Previous)

        Relative return example:
            Y1 = 21.6%
            Y2 = 15.3%

        Relative return Y2 to Y1 = (15.3% - 21.6%) = -6.3%
*/
enum class AbsOrRel { abs, rel };