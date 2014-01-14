SRC= Makefile gis_spr3.tex bibliografia.bib

# pdf, ps, gs, gs2, dvi
default: t.ps

pdf: t.pdf
	echo "Making DVI to PDF"

ps: t.ps

gs: t.ps
	gv -scale -2 -geometry +0+0 gis_spr3.ps

gs2: t.ps
	psnup -2 t.ps > tt.ps
	gv -landscape -scale -1 -geometry +0+0 tt.ps

dvi: t.dvi
	@xdvi + -s 4 -topmargin 6cm -bg white -keep -geometry 715x724+0+0 gis_spr3

ed:
	vim gis_spr3

t: default


t.dvi: $(SRC)
	latex gis_spr3
	latex gis_spr3
	bibtex gis_spr3
	latex gis_spr3 
	latex gis_spr3

t.pdf: t.dvi
	dvipdf t.dvi

t.ps: t.dvi
	dvips gis_spr3.dvi -o gis_spr3.ps

tgz: clean
	( D=`basename $$PWD`; cd ..; tar czf $$D.tgz $$D; ls -l $$D.tgz )

aspell:
	aspell --lang=pl  -t check gis_spr3
	
v: t t.ps

clean:
	rm -f *.dvi *.bbl *.blg *.log *.toc *.aux *.ps *.lof *.pdf

