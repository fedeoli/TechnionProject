// Auto-generated. Do not edit!

// (in-package gtec_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class RadarRangeAzimuth {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.numRangeBins = null;
      this.numVirtualAntennas = null;
      this.data = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('numRangeBins')) {
        this.numRangeBins = initObj.numRangeBins
      }
      else {
        this.numRangeBins = 0;
      }
      if (initObj.hasOwnProperty('numVirtualAntennas')) {
        this.numVirtualAntennas = initObj.numVirtualAntennas
      }
      else {
        this.numVirtualAntennas = 0;
      }
      if (initObj.hasOwnProperty('data')) {
        this.data = initObj.data
      }
      else {
        this.data = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type RadarRangeAzimuth
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [numRangeBins]
    bufferOffset = _serializer.int16(obj.numRangeBins, buffer, bufferOffset);
    // Serialize message field [numVirtualAntennas]
    bufferOffset = _serializer.int16(obj.numVirtualAntennas, buffer, bufferOffset);
    // Serialize message field [data]
    bufferOffset = _arraySerializer.float64(obj.data, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type RadarRangeAzimuth
    let len;
    let data = new RadarRangeAzimuth(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [numRangeBins]
    data.numRangeBins = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [numVirtualAntennas]
    data.numVirtualAntennas = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [data]
    data.data = _arrayDeserializer.float64(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += 8 * object.data.length;
    return length + 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'gtec_msgs/RadarRangeAzimuth';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '1150f685277d05fb6d94e264639cdc1e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    int16 numRangeBins
    int16 numVirtualAntennas
    float64[] data
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    string frame_id
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new RadarRangeAzimuth(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.numRangeBins !== undefined) {
      resolved.numRangeBins = msg.numRangeBins;
    }
    else {
      resolved.numRangeBins = 0
    }

    if (msg.numVirtualAntennas !== undefined) {
      resolved.numVirtualAntennas = msg.numVirtualAntennas;
    }
    else {
      resolved.numVirtualAntennas = 0
    }

    if (msg.data !== undefined) {
      resolved.data = msg.data;
    }
    else {
      resolved.data = []
    }

    return resolved;
    }
};

module.exports = RadarRangeAzimuth;
