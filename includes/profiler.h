#ifndef PROFILER_H
# define PROFILER_H

# include <SDL.h>
# include <stdio.h>

# define PR_RESOLUTION 256
typedef struct		s_profiler
{
	unsigned int	start[PR_RESOLUTION];
	unsigned int	end[PR_RESOLUTION];
}					prof_t;


# define PR_START(num) {\
	__profiler.start[num] = SDL_GetTicks();\
}

# define PR_END(num) {\
	__profiler.end[num] = SDL_GetTicks();\
}

# define PR_ELAPSED(num) (__profiler.end[num] - __profiler.start[num])

# define PR_DROP(num) {\
	printf("Time elapsed: %d ms\n", PR_ELAPSED(num));\
}

# define PR_FLUSH(num, string) {\
	printf("%s%d ms\n", string, PR_ELAPSED(num));\
}

# define PR_CLEAR {\
	bzero(&__profiler.start, sizeof(int) * PR_RESOLUTION);\
	bzero(&__profiler.end, sizeof(int) * PR_RESOLUTION);\
}

prof_t				__profiler;
#endif