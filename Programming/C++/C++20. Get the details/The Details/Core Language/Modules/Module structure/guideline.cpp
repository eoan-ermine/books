module;

#include <headers for libraries not modularized so far>

export module math;

import <importing of other modules>

<non-exported declarations>	// names only visible inside the module

export namespace math {
	<exported declarations>	// exported names
}
