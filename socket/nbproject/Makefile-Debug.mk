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
	${OBJECTDIR}/_ext/rcapl/workspace/sanath/socket/ServerSocket.o \
	${OBJECTDIR}/_ext/rcapl/workspace/sanath/socket/Socket.o \
	${OBJECTDIR}/ClientSocket.o

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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-Linux-x86/libsocket.so

dist/Debug/GNU-Linux-x86/libsocket.so: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${LINK.cc} -shared -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsocket.so -fPIC ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/rcapl/workspace/sanath/socket/ServerSocket.o: nbproject/Makefile-${CND_CONF}.mk /rcapl/workspace/sanath/socket/ServerSocket.cc 
	${MKDIR} -p ${OBJECTDIR}/_ext/rcapl/workspace/sanath/socket
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -I/usr/include/c++/4.3 -I/usr/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/rcapl/workspace/sanath/socket/ServerSocket.o /rcapl/workspace/sanath/socket/ServerSocket.cc

${OBJECTDIR}/_ext/rcapl/workspace/sanath/socket/Socket.o: nbproject/Makefile-${CND_CONF}.mk /rcapl/workspace/sanath/socket/Socket.cc 
	${MKDIR} -p ${OBJECTDIR}/_ext/rcapl/workspace/sanath/socket
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -I/usr/include/c++/4.3 -I/usr/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/rcapl/workspace/sanath/socket/Socket.o /rcapl/workspace/sanath/socket/Socket.cc

${OBJECTDIR}/ClientSocket.o: nbproject/Makefile-${CND_CONF}.mk ClientSocket.cc 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Werror -I/usr/include/c++/4.3 -I/usr/include -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/ClientSocket.o ClientSocket.cc

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/libsocket.so

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
