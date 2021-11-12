build:
	@if test -d bin; then \
		echo; \
	else \
		cmake -S . -B bin; \
	fi

	@cmake --build bin

run:
	bin/game