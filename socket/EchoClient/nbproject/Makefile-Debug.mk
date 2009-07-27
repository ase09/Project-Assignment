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
	${OBJECTDIR}/EchoClient.o

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
LDLIBSOPTIONS=-Wl,-rpath ../dist/Debug/GNU-Linux-x86 -L../dist/Debug/GNU-Linux-x86 -lsocket

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-Linux-x86/echoclient

dist/Debug/GNU-Linux-x86/echoclient: ../dist/Debug/GNU-Linux-x86/libsocket.so

dist/Debug/GNU-Linux-x86/echoclient: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/echoclient ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/EchoClient.o: nbproject/Makefile-${CND_CONF}.mk EchoClient.cc 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I.. -MMD -MP -MF $@.d -o ${OBJECTDIR}/EchoClient.o EchoClient.cc

# Subprojects
.build-subprojects:
	cd .. && ${MAKE}  -f Makefile CONF=Debug
	cd .. && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/echoclient

# Subprojects
.clean-subprojects:
	cd .. && ${MAKE}  -f Makefile CONF=Debug clean
	cd .. && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
