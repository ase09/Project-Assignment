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
	${OBJECTDIR}/BattleshipsAPIValidator.o

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
LDLIBSOPTIONS=-Wl,-rpath ../dist/Debug/GNU-Linux-x86 -L../dist/Debug/GNU-Linux-x86 -lBattleshipsAPI -Wl,-rpath ../../../socket/dist/Debug/GNU-Linux-x86 -L../../../socket/dist/Debug/GNU-Linux-x86 -lsocket -llog4cplus -lpthread

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-Linux-x86/validator

dist/Debug/GNU-Linux-x86/validator: ../dist/Debug/GNU-Linux-x86/libBattleshipsAPI.so

dist/Debug/GNU-Linux-x86/validator: ../../../socket/dist/Debug/GNU-Linux-x86/libsocket.so

dist/Debug/GNU-Linux-x86/validator: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/validator ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/BattleshipsAPIValidator.o: nbproject/Makefile-${CND_CONF}.mk BattleshipsAPIValidator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../../../socket -I.. -MMD -MP -MF $@.d -o ${OBJECTDIR}/BattleshipsAPIValidator.o BattleshipsAPIValidator.cpp

# Subprojects
.build-subprojects:
	cd .. && ${MAKE}  -f Makefile CONF=Debug
	cd ../../../socket && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/validator

# Subprojects
.clean-subprojects:
	cd .. && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../../../socket && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
