
#ifndef WIN32
#include <libgen.h>
#include <unistd.h>
#include <stdio.h>
#endif

#include "GUIDOParse.h"
#include "GUIDOEngine.h"
#include "GUIDOPianoRollAPI.h"
#include "SVGDevice.h"
#include "SVGSystem.h"

using namespace std;

const int kDefaultWidth	   = 1024;
const int kDefaultHeight   = 400;
const int kDefaultMinPitch = 0;
const int kDefaultMaxPitch = 127;

const char* kOptions[] = { "-help", "-o", "-width", "-height", "-start", "-end", "-minpitch", "-maxpitch" };
enum { kHelp, kOutput, kWidth, kHeight, kStart, kEnd, kMinPitch, kMaxPitch, kMaxOpt };

static void usage(char* name)
{
#ifndef WIN32
	const char* tool = basename (name);
#else
	const char* tool = name;
#endif
	cerr << "usage: " << tool << " gmnfile [options] " << endl;
    cerr << "options: -o              : set the output file (if not, output is standard output)" << endl;
	cerr << "         -width value    : set the output width (default is " << kDefaultWidth << ")" << endl;
	cerr << "         -height value   : set the output height (default is " << kDefaultHeight << ")" << endl;
	cerr << "         -start date     : set time zone start" << endl;
	cerr << "         -end date       : set time zone end" << endl;
    cerr << "         -minpitch value : set minimum midi pitch (default is " << kDefaultMinPitch << ")" << endl;
	cerr << "         -maxpitch value : set maximum midi pitch (default is " << kDefaultMaxPitch << ")" << endl;
	system("PAUSE"); // REM: tmp
    exit(1);
}

static void error(GuidoErrCode err)
{
    if (err != guidoNoErr) {
        cerr << "error #" << err << ": " << GuidoGetErrorString (err) << endl;
        system("PAUSE"); // REM: tmp
        exit(err);
    }
}

static void checkusage(int argc, char **argv)
{
	if (argc == 1 || *(argv[1]) == '-')
        usage(argv[0]);
    else {
        for (int i = 1; i < argc; i++) {
            if (!strcmp(argv[i], kOptions[kHelp]))
                usage(argv[0]);
            else if (*argv[i] == '-') {
                bool unknownOpt = true;

                for (int n = 1; (n < kMaxOpt) && unknownOpt; n++) {
                    if (!strcmp (argv[i], kOptions[n]))
                        unknownOpt = false;
                }

                if (unknownOpt || i + 1 >= argc || *(argv[i + 1]) == '-')
                    usage(argv[0]);
            }
        }
    }
}

static const char* getInputFile(int argc, char *argv[])
{
	int i;

	for (i = 1; i < argc; i++) {
		if (*(argv[i]) != '-')
            break;
    }

	return (i < argc) ? argv[i] : 0;
}

static GuidoDate ldateopt(int argc, char **argv, const char* opt, GuidoDate defaultvalue)
{
	for (int i = 1; i < argc; i++) {
		if (!strcmp (argv[i], opt)) {
			i++;

			if (i >= argc)
                usage(argv[0]);
			else {
				int n,d;

				if (sscanf(argv[i], "%d/%d", &n, &d) == 2) {
					GuidoDate ret = {n, d};
					return ret;
				}
                else if (sscanf(argv[i], "%d", &n) == 1) {
					GuidoDate ret = {n, 1};
					return ret;
				}
                else
                    usage(argv[0]);
			}
		}
	}

	return defaultvalue;
}

static int lintopt(int argc, char **argv, const char* opt, int defaultvalue)
{
	for (int i = 1; i < argc; i++) {
		if (!strcmp(argv[i], opt)) {
			i++;

			if (i >= argc)
                usage(argv[0]);
			else
				return atoi(argv[i]);
		}
	}

	return defaultvalue;
}

static char *getOutputFileOpt(int argc, char **argv)
{
	for (int i = 1; i < argc; i++) {
		if (!strcmp(argv[i], "-o")) {
			i++;

			if (i >= argc || *(argv[i]) == '-')
                usage(argv[0]);
			else
				return argv[i];
		}
	}

    return NULL;
}

int main(int argc, char **argv)
{
 	SVGSystem sys;
    
    std::streambuf *buf = std::cout.rdbuf();

    /**** Check output file ****/
    const char *outputFile = getOutputFileOpt(argc, argv);

    ofstream fileOutput;

    if (outputFile != NULL) {
        fileOutput = ofstream(outputFile, ios::out | ios::trunc);

        if (!fileOutput.fail())
            buf = fileOutput.rdbuf();
    }
    /***************************/

    std::ostream out(buf);

    SVGDevice dev(out, &sys, 0);
	
	checkusage(argc, argv);
	
	GuidoInitDesc gd = { &dev, 0, 0, 0 };
    GuidoInit(&gd);

    const char* fileName = getInputFile(argc, argv);

	int w        = lintopt(argc, argv, kOptions[kWidth], kDefaultWidth);
	int h        = lintopt(argc, argv, kOptions[kHeight], kDefaultHeight);
    int minPitch = lintopt(argc, argv, kOptions[kMinPitch], kDefaultMinPitch);
    int maxPitch = lintopt(argc, argv, kOptions[kMaxPitch], kDefaultMaxPitch);

	GuidoDate defDate = {0,1};
	GuidoDate start   = ldateopt(argc, argv, kOptions[kStart], defDate);
	GuidoDate end     = ldateopt(argc, argv, kOptions[kEnd], defDate);

	GuidoParser *parser = GuidoOpenParser();
	ARHandler    arh    = GuidoFile2AR(parser, fileName);

    GuidoErrCode err;

	if (arh) {
        GuidoPianoRoll *pianoRoll = GuidoCreatePianoRoll(false);

        err = GuidoSetARToPianoRoll(pianoRoll, arh);
        error(err);

        /*err = GuidoSetPianoRollCanvasDimensions(pianoRoll, w, h);
        error(err);
        
        err = GuidoSetPianoRollTimeLimits(pianoRoll, start, end);
        error(err);

        err = GuidoSetPianoRollPitchLimits(pianoRoll, 60, 71);
        error(err);

        err = GuidoPianoRollEnableKeyboard(pianoRoll, false);
        error(err);

        err = GuidoPianoRollEnableRandomVoicesColor(pianoRoll, true);
        error(err);
        
        err = GuidoPianoRollSetColorToVoice(pianoRoll, 1, 255, 0, 0, 100);
        error(err);
        
        err = GuidoPianoRollSetColorToVoice(pianoRoll, 2, 0, 255, 0, 100);
        error(err);
        
        err = GuidoPianoRollSetColorToVoice(pianoRoll, 3, 0, 0, 255, 100);
        error(err);

        int keyboardWidth;
        err = GuidoGetPianoRollKeyboardWidth(pianoRoll, keyboardWidth);
        error(err);*/

        err = GuidoGetPianoRollRenderingFromAR(pianoRoll, &dev);
        error(err);

        GuidoDestroyPianoRoll(pianoRoll);

		GuidoFreeAR(arh);
	}
	else {
		int line, col;
		
        err = GuidoParserGetErrorCode(parser, line, col, 0); // REM: l'erreur n'est pas r�cup�r�e si l'arh a simplement mal �t� instanci�
		error(err);
	}

	GuidoCloseParser(parser);

    return 0;
}