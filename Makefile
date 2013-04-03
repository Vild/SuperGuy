.PHONY: all clean linux windows todo docs docsnopush

DATE := $(shell date)

all: linux

clean:
	+rm -rf bin obj
	
linux:
	+$(MAKE) -f linux.mk

windows:
	+$(MAKE) -f windows.mk

todo:
	+$(MAKE) -f linux.mk todo
	
docs: docsnopush
	cd docs
	git add *
	git commit -s -a "Updated docs: $(DATE)"
	git push origin gh-pages
	cd ..
	
docsnopush:
	doxygen Doxyfile
	
help:
	@echo ====Help====
	@echo all   - Builds for Linux and Windows
	@echo linux - Builds for Linux
	@echo windows - Builds for Windows
	@echo todo - Prints all TODO and FIXME
	@echo docs - Builds docs into the docs folder and pushes it to the remote server
	@echo docsnopush - Builds docs into the docs folder
	@echo ============
	
