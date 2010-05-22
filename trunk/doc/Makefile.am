# Makefile.am

AUTOMAKE_OPTIONS = foreign

man_MANS = \
	logc_defines.3 \
	logc_changeLogLevel.3 \
	logc_log.3 \
	logc_logArray.3 \
	logc_logArrayBasic.3 \
	logc_logArrayFine.3 \
	logc_logArrayFinest.3 \
	logc_logArrayInfo.3 \
	logc_logArrayWarning.3 \
	logc_logBasic.3 \
	logc_logEnter.3 \
	logc_logError.3 \
	logc_logErrorBasic.3 \
	logc_logErrorFine.3 \
	logc_logErrorFinest.3 \
	logc_logErrorInfo.3 \
	logc_logErrorWarning.3 \
	logc_logFine.3 \
	logc_logFinest.3 \
	logc_logInfo.3 \
	logc_logLeave.3 \
	logc_logWarning.3 \
	logc_logger.3 \
	logc_registerLogger.3 \
	logc_removeLogger.3 \
	logc_setLogFile.3 \
	logc_setLogFormat.3

dist_doc_DATA = \
	nglogc_manual.pdf

# create the nglogc documentation pdf file
DOCUMENT=nglogc_manual

document: $(DOCUMENT).tex
	pdflatex $(DOCUMENT).tex
	rm -f $(DOCUMENT).log $(DOCUMENT).toc $(DOCUMENT).aux

EXTRA_DIST = \
	$(man_MANS) \
	nglogc_manual.tex \
	nglogo.png

