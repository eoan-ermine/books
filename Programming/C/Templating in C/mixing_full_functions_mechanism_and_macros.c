static inline int process_image(void *img, int width, int height, const int n) {
	for(int y = 0; y < height; ++y) {
		for(int x = 0; x < width; ++x) {
			if 		(n == 0) 	foo(img, x, y);
			else if (n == 1) 	bar(img, x, y);
			else				baz(img, x, y);
		}
	}
}

#define DECLARE_PROCESS_IMAGE_FUNC(name, n)					\
int process_image_##name(void *img, int width, int height)	\
{															\
	return process_image(img, width, height, n);			\
}

DECLARE_PROCESS_IMAGE_FUNC(foo, 0)
DECLARE_PROCESS_IMAGE_FUNC(bar, 1)
DECLARE_PROCESS_IMAGE_FUNC(baz, 2)

int main() {}
