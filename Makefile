CC = g++ # Flag for implicit rules
V = c++17
CFLAGS = -g # Flag for implicit rules. Turn on debug info
FOLDER = build
TIPO=norecursivo
LIST:=$(shell ls tests/matrices/*.txt | cut -f 1 -d '.' | cut -d_ -f2-)
FILES:=$(shell ls tests/matrices/*.txt | cut -d/ -f2-)

allsec: clean buildsec runtestsec

allpar: clean buildpar runtestpar

buildsec:
	rm -rf ${FOLDER}/tests
	mkdir -p ${FOLDER}/tests
	$(info    Compile files)
	for number in $(LIST) ; do ${CC} -std=${V} ${TIPO}/serial/ser-tsp-bb.cpp -o ${FOLDER}/tests/main-$$number.out -DSIZE=$$number ; done

buildpar:
	rm -rf ${FOLDER}/tests
	mkdir -p ${FOLDER}/tests
	$(info    Compile files)
	for number in $(LIST) ; do ${CC} -std=${V} -Xpreprocessor -fopenmp ${TIPO}/paralelo/par-tsp-bb.cpp -o ${FOLDER}/tests/main-$$number.out -lomp -DSIZE=$$number ; done

runtestsec:
	$(info    Run programs)
	./tests/run.sh > tests/run.log

runtestpar:
	$(info    Run programs, with 4 threads)
	./tests/run.sh 4 > tests/run.log

runparser:
	$(info    Compile main.cpp in src/ folder)
	${CC} -std=${V} -Xpreprocessor -fopenmp main.cpp Algoritmo/*.cpp -o main.out -lomp -w
	$(info    Running Parser)
	${FOLDER}/osx/main.out

clean:
	rm -rf ${FOLDER}