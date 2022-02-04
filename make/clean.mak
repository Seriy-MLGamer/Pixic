clean_folders=\
	if ! rmdir $(bin); then cd .; fi;\
	if ! rmdir $(obj); then cd .; fi;\
	if ! rmdir $(lib); then cd .; fi