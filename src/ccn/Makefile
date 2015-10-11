LIBS=/Users/cwood/Projects/PARC/Review/

CCN_DEPENDENCIES=/usr/local/ccnx/dependencies/build/
CCN_DEPENDENCIES_INCLUDE=-I$(CCN_DEPENDENCIES)/include
CCN_DEPENDENCIES_LIB=$(CCN_DEPENDENCIES)/lib/
CCN_BUILD=/Users/cwood/Projects/PARC/Review/build/
CCN_BUILD_INCLUDES=-I$(CCN_BUILD)/include
CCN_BUILD_LIB=$(CCN_BUILD)/lib

CCN_LIBRARIES=$(CCN_BUILD_LIB)/libparc.a $(CCN_BUILD_LIB)/libccnx_api_portal.a $(CCN_BUILD_LIB)/libccnx_common.a $(CCN_BUILD_LIB)/liblongbow-ansiterm.a $(CCN_BUILD_LIB)/liblongbow.a $(CCN_BUILD_LIB)/librta.a $(CCN_BUILD_LIB)/libccnx_api_control.a $(CCN_BUILD_LIB)/libccnx_api_notify.a
EXTERNAL_LIBRARIES= -levent -lcrypto

all:
	gcc -v -o ccn-client ccn-client.c common.c fileio.c $(EXTERNAL_LIBRARIES) $(CCN_LIBRARIES) $(CCN_BUILD_INCLUDES) $(CCN_DEPENDENCIES_INCLUDE)
	gcc -v -o ccn-server ccn-server.c common.c fileio.c $(EXTERNAL_LIBRARIES) $(CCN_LIBRARIES) $(CCN_BUILD_INCLUDES) $(CCN_DEPENDENCIES_INCLUDE)

clean:
	rm ccn-client ccn-server
