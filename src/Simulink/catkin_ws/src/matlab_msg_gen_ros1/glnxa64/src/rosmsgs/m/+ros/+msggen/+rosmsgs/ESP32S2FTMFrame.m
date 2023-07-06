
classdef ESP32S2FTMFrame < ros.Message
    %ESP32S2FTMFrame MATLAB implementation of rosmsgs/ESP32S2FTMFrame
    %   This class was automatically generated by
    %   ros.internal.pubsubEmitter.
    %   Copyright 2014-2020 The MathWorks, Inc.
    properties (Constant)
        MessageType = 'rosmsgs/ESP32S2FTMFrame' % The ROS message type
    end
    properties (Constant, Hidden)
        MD5Checksum = 'a1b894ddb8209b3399fd6809e514d068' % The MD5 Checksum of the message definition
        PropertyList = { 'Rssi' 'Rtt' 'T1' 'T2' 'T3' 'T4' } % List of non-constant message properties
        ROSPropertyList = { 'rssi' 'rtt' 't1' 't2' 't3' 't4' } % List of non-constant ROS message properties
        PropertyMessageTypes = { '' ...
            '' ...
            '' ...
            '' ...
            '' ...
            '' ...
            } % Types of contained nested messages
    end
    properties (Constant)
    end
    properties
        Rssi
        Rtt
        T1
        T2
        T3
        T4
    end
    methods
        function set.Rssi(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'ESP32S2FTMFrame', 'Rssi');
            obj.Rssi = int32(val);
        end
        function set.Rtt(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'ESP32S2FTMFrame', 'Rtt');
            obj.Rtt = int32(val);
        end
        function set.T1(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'ESP32S2FTMFrame', 'T1');
            obj.T1 = int64(val);
        end
        function set.T2(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'ESP32S2FTMFrame', 'T2');
            obj.T2 = int64(val);
        end
        function set.T3(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'ESP32S2FTMFrame', 'T3');
            obj.T3 = int64(val);
        end
        function set.T4(obj, val)
            validClasses = {'numeric'};
            validAttributes = {'nonempty', 'scalar'};
            validateattributes(val, validClasses, validAttributes, 'ESP32S2FTMFrame', 'T4');
            obj.T4 = int64(val);
        end
    end
    methods (Static, Access = {?matlab.unittest.TestCase, ?ros.Message})
        function obj = loadobj(strObj)
        %loadobj Implements loading of message from MAT file
        % Return an empty object array if the structure element is not defined
            if isempty(strObj)
                obj = ros.msggen.rosmsgs.ESP32S2FTMFrame.empty(0,1);
                return
            end
            % Create an empty message object
            obj = ros.msggen.rosmsgs.ESP32S2FTMFrame(strObj);
        end
    end
end
