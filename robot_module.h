/* 
 * File:   robots.h
 * Author: m79lol
 *
 */

#ifndef ROBOT_MODULE_H
#define	ROBOT_MODULE_H

class Robot {
    protected:
        Robot() {}
    public: 
        virtual FunctionResult* executeFunction(regval command_index, regval *args) = 0;
        virtual void axisControl(regval axis_index, regval value) = 0;
        virtual ~Robot() {}
};

class RobotModule {
    protected:
        RobotModule() {}
    public: 
        virtual int init() = 0;
        virtual FunctionData* getFunctions(int *count_functions) = 0;
        virtual AxisData* getAxis(int *count_axis) = 0;
        virtual Robot* robotRequire() = 0;
        virtual void robotFree(Robot *robot) = 0;
        virtual void final() = 0;
        virtual void destroy() = 0;
        virtual ~RobotModule() {}
};
typedef RobotModule* (*getRobotModuleObject_t)();

#endif	/* ROBOT_MODULE_H */

