.PHONY: clean All

All:
	@echo "----------Building project:[ mat5writer - Debug ]----------"
	@cd "mat5writer" && "$(MAKE)" -f  "mat5writer.mk"
clean:
	@echo "----------Cleaning project:[ mat5writer - Debug ]----------"
	@cd "mat5writer" && "$(MAKE)" -f  "mat5writer.mk" clean
