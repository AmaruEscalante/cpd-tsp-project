CC = g++ # Flag for implicit rules
V = c++17
CFLAGS = -g # Flag for implicit rules. Turn on debug info
FOLDER = build
LIST:=$(shell ls tests/*.txt | cut -f 1 -d '.' | cut -d_ -f2-)
FILES:=$(shell ls tests/*.txt | cut -d/ -f2-)

all: clean buildsec run

buildsec:
	rm -rf ${FOLDER}
	mkdir ${FOLDER}
	$(info    Compile files)
	@echo $(LIST)
	for number in $(LIST) ; do ${CC} -std=${V} norecursivo/tsp-node.cpp -o ${FOLDER}/main-$$number.out -DSIZE=$$number ; done

buildpar:
	rm -rf ${FOLDER}
	mkdir ${FOLDER}
	$(info    Compile files)
	@echo $(LIST)
	for number in $(LIST) ; do ${CC} -std=${V} norecursivo/tsp-node-par.cpp -o ${FOLDER}/main-$$number.out -DSIZE=$$number ; done

run:
	$(info    Run programs)
	./tests/run.sh > run.log

clean:
	rm -rf ${FOLDER}