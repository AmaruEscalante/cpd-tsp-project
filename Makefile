CC = g++ # Flag for implicit rules
V = c++17
CFLAGS = -g # Flag for implicit rules. Turn on debug info
FOLDER = build
LIST:=$(shell ls tests/matrices/*.txt | cut -f 1 -d '.' | cut -d_ -f2-)
FILES:=$(shell ls tests/matrices/*.txt | cut -d/ -f2-)

allsec: clean buildsec runtest

debug:
	g++ -std=c++17 -Xpreprocessor -fopenmp norecursivo/paralelo/par-dfs-v2-tsp.cpp -lomp -DSIZE=100

buildsec:
	rm -rf ${FOLDER}/tests
	mkdir -p ${FOLDER}/tests
	$(info    Compile files)
	for number in $(LIST) ; do ${CC} -std=${V} norecursivo/serial/tsp-dfs-v2.cpp -o ${FOLDER}/tests/main-$$number.out -DSIZE=$$number ; done

buildpar:
	rm -rf ${FOLDER}/tests
	mkdir -p ${FOLDER}/tests
	$(info    Compile files)
	for number in $(LIST) ; do ${CC} -std=${V} norecursivo/paralelo/par-dfs-v2-tsp.cpp -o ${FOLDER}/tests/main-$$number.out -DSIZE=$$number ; done

runtest:
	$(info    Run programs)
	./tests/run.sh > tests/run.log

runparser:
	$(info    Compile main.cpp in src/ folder)
	mkdir -p ${FOLDER}/osx
	g++ --std=c++11 -g src/main.cpp src/Tester/*.cpp -o ${FOLDER}/osx/main.out -w
	$(info    Running Parser)
	${FOLDER}/osx/main.out

clean:
	rm -rf ${FOLDER}