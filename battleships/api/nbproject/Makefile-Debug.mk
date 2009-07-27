#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/rcapl/workspace/sanath/battleships/api/Header.o \
	${OBJECTDIR}/Accept.o \
	${OBJECTDIR}/Reject.o \
	${OBJECTDIR}/Initiate.o \
	${OBJECTDIR}/_ext/rcapl/workspace/sanath/battleships/api/SalvoResponse.o \
	${OBJECTDIR}/_ext/rcapl/workspace/sanath/battleships/api/Salvo.o \
	${OBJECTDIR}/_ext/rcapl/workspace/sanath/battleships/api/Message.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-Wl,-rpath /rcapl/workspace/sanath/socket/dist/Debug/GNU-Linux-x86 -L/rcapl/workspace/sanath/socket/dist/Debug/GNU-Linux-x86 -lsocket

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-Linux-x86/libBattleshipsAPI.so

dist/Debug/GNU-Linux-x86/libBattleshipsAPI.so: /rcapl/workspace/sanath/socket/dist/Debug/GNU-Linux-x86/libsocket.so

dist/Debug/GNU-Linux-x86/libBattleshipsAPI.so: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${LINK.cc} -shared -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libBattleshipsAPI.so -fPIC ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/rcapl/workspace/sanath/battleships/api/Header.o: nbproject/Makefile-${CND_CONF}.mk /rcapl/workspace/sanath/battleships/api/Header.cc 
	${MKDIR} -p ${OBJECTDIR}/_ext/rcapl/workspace/sanath/battleships/api
	${RM} $@.d
	$(COMPILE.cc) -g -I/rcapl/workspace/sanath/socket -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/rcapl/workspace/sanath/battleships/api/Header.o /rcapl/workspace/sanath/battleships/api/Header.cc

${OBJECTDIR}/Accept.o: nbproject/Makefile-${CND_CONF}.mk Accept.cc 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/rcapl/workspace/sanath/socket -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Accept.o Accept.cc

${OBJECTDIR}/Reject.o: nbproject/Makefile-${CND_CONF}.mk Reject.cc 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/rcapl/workspace/sanath/socket -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Reject.o Reject.cc

${OBJECTDIR}/Initiate.o: nbproject/Makefile-${CND_CONF}.mk Initiate.cc 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/rcapl/workspace/sanath/socket -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Initiate.o Initiate.cc

${OBJECTDIR}/_ext/rcapl/workspace/sanath/battleships/api/SalvoResponse.o: nbproject/Makefile-${CND_CONF}.mk /rcapl/workspace/sanath/battleships/api/SalvoResponse.cc 
	${MKDIR} -p ${OBJECTDIR}/_ext/rcapl/workspace/sanath/battleships/api
	${RM} $@.d
	$(COMPILE.cc) -g -I/rcapl/workspace/sanath/socket -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/rcapl/workspace/sanath/battleships/api/SalvoResponse.o /rcapl/workspace/sanath/battleships/api/SalvoResponse.cc

${OBJECTDIR}/_ext/rcapl/workspace/sanath/battleships/api/Salvo.o: nbproject/Makefile-${CND_CONF}.mk /rcapl/workspace/sanath/battleships/api/Salvo.cc 
	${MKDIR} -p ${OBJECTDIR}/_ext/rcapl/workspace/sanath/battleships/api
	${RM} $@.d
	$(COMPILE.cc) -g -I/rcapl/workspace/sanath/socket -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/rcapl/workspace/sanath/battleships/api/Salvo.o /rcapl/workspace/sanath/battleships/api/Salvo.cc

${OBJECTDIR}/_ext/rcapl/workspace/sanath/battleships/api/Message.o: nbproject/Makefile-${CND_CONF}.mk /rcapl/workspace/sanath/battleships/api/Message.cc 
	${MKDIR} -p ${OBJECTDIR}/_ext/rcapl/workspace/sanath/battleships/api
	${RM} $@.d
	$(COMPILE.cc) -g -I/rcapl/workspace/sanath/socket -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/rcapl/workspace/sanath/battleships/api/Message.o /rcapl/workspace/sanath/battleships/api/Message.cc

# Subprojects
.build-subprojects:
	cd /rcapl/workspace/sanath/socket && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/libBattleshipsAPI.so

# Subprojects
.clean-subprojects:
	cd /rcapl/workspace/sanath/socket && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
