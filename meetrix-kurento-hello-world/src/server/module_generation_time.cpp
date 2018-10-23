
    extern "C" {const char * getGenerationTime ();}
    const char * getGenerationTime () {return __DATE__ " " __TIME__;}