#Dependencies.
#compilation.mak

clean:
	if ! rm $(bin)/*; then true; fi
	if ! rmdir $(bin); then true; fi
	if ! rm $(obj)/*; then true; fi
	if ! rmdir $(obj); then true; fi
	if ! rm $(lib)/*; then true; fi
	if ! rmdir $(lib); then true; fi
	if ! rmdir $(arch_root); then true; fi