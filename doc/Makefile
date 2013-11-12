SRC= Makefile gis_dokumentacja.tex bibliografia.bib

# pdf, ps, gs, gs2, dvi
default: t.ps

pdf: t.pdf
	echo "Making DVI to PDF"

ps: t.ps

gs: t.ps
	gv -scale -2 -geometry +0+0 gis_dokumentacja.ps

gs2: t.ps
	psnup -2 t.ps > tt.ps
	gv -landscape -scale -1 -geometry +0+0 tt.ps

dvi: t.dvi
	@xdvi + -s 4 -topmargin 6cm -bg white -keep -geometry 715x724+0+0 gis_dokumentacja

ed:
	vim gis_dokumentacja

t: default


t.dvi: $(SRC)
	latex gis_dokumentacja
	latex gis_dokumentacja
	bibtex gis_dokumentacja
	latex gis_dokumentacja 
	latex gis_dokumentacja

t.pdf: t.dvi
	dvipdf t.dvi

t.ps: t.dvi
	dvips gis_dokumentacja.dvi -o gis_dokumentacja.ps

tgz: clean
	( D=`basename $$PWD`; cd ..; tar czf $$D.tgz $$D; ls -l $$D.tgz )

aspell:
	aspell --lang=pl  -t check gis_dokumentacja
	
v: t t.ps

clean:
	rm -f *.dvi *.bbl *.blg *.log *.toc *.aux *.ps *.lof *.pdf

