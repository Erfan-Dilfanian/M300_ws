// Auto-generated. Do not edit!

// (in-package forest_fire_detection_system.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class SingleFireIR {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.img_width = null;
      this.img_height = null;
      this.resize_img_width = null;
      this.resize_img_height = null;
      this.target_type = null;
      this.img_x = null;
      this.img_y = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('img_width')) {
        this.img_width = initObj.img_width
      }
      else {
        this.img_width = 0;
      }
      if (initObj.hasOwnProperty('img_height')) {
        this.img_height = initObj.img_height
      }
      else {
        this.img_height = 0;
      }
      if (initObj.hasOwnProperty('resize_img_width')) {
        this.resize_img_width = initObj.resize_img_width
      }
      else {
        this.resize_img_width = 0;
      }
      if (initObj.hasOwnProperty('resize_img_height')) {
        this.resize_img_height = initObj.resize_img_height
      }
      else {
        this.resize_img_height = 0;
      }
      if (initObj.hasOwnProperty('target_type')) {
        this.target_type = initObj.target_type
      }
      else {
        this.target_type = 0;
      }
      if (initObj.hasOwnProperty('img_x')) {
        this.img_x = initObj.img_x
      }
      else {
        this.img_x = 0.0;
      }
      if (initObj.hasOwnProperty('img_y')) {
        this.img_y = initObj.img_y
      }
      else {
        this.img_y = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SingleFireIR
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [img_width]
    bufferOffset = _serializer.uint16(obj.img_width, buffer, bufferOffset);
    // Serialize message field [img_height]
    bufferOffset = _serializer.uint16(obj.img_height, buffer, bufferOffset);
    // Serialize message field [resize_img_width]
    bufferOffset = _serializer.uint16(obj.resize_img_width, buffer, bufferOffset);
    // Serialize message field [resize_img_height]
    bufferOffset = _serializer.uint16(obj.resize_img_height, buffer, bufferOffset);
    // Serialize message field [target_type]
    bufferOffset = _serializer.uint8(obj.target_type, buffer, bufferOffset);
    // Serialize message field [img_x]
    bufferOffset = _serializer.float32(obj.img_x, buffer, bufferOffset);
    // Serialize message field [img_y]
    bufferOffset = _serializer.float32(obj.img_y, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SingleFireIR
    let len;
    let data = new SingleFireIR(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [img_width]
    data.img_width = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [img_height]
    data.img_height = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [resize_img_width]
    data.resize_img_width = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [resize_img_height]
    data.resize_img_height = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [target_type]
    data.target_type = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [img_x]
    data.img_x = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [img_y]
    data.img_y = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 17;
  }

  static datatype() {
    // Returns string type for a message object
    return 'forest_fire_detection_system/SingleFireIR';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '9ea94f8510b24f699c5a36dcda64a4f8';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    
    # image shape
    uint16 img_width
    uint16 img_height
    
    # reszie shape
    uint16 resize_img_width
    uint16 resize_img_height
    
    # target type
    uint8 IS_BACKGROUND = 0
    uint8 IS_HEAT = 1
    uint8 IS_UNKNOWN = 255
    
    uint8 target_type
    
    # the x and y pos (sub-pixel) of the single fire, opencv style coordinates
    float32 img_x
    float32 img_y
    
    
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
    const resolved = new SingleFireIR(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.img_width !== undefined) {
      resolved.img_width = msg.img_width;
    }
    else {
      resolved.img_width = 0
    }

    if (msg.img_height !== undefined) {
      resolved.img_height = msg.img_height;
    }
    else {
      resolved.img_height = 0
    }

    if (msg.resize_img_width !== undefined) {
      resolved.resize_img_width = msg.resize_img_width;
    }
    else {
      resolved.resize_img_width = 0
    }

    if (msg.resize_img_height !== undefined) {
      resolved.resize_img_height = msg.resize_img_height;
    }
    else {
      resolved.resize_img_height = 0
    }

    if (msg.target_type !== undefined) {
      resolved.target_type = msg.target_type;
    }
    else {
      resolved.target_type = 0
    }

    if (msg.img_x !== undefined) {
      resolved.img_x = msg.img_x;
    }
    else {
      resolved.img_x = 0.0
    }

    if (msg.img_y !== undefined) {
      resolved.img_y = msg.img_y;
    }
    else {
      resolved.img_y = 0.0
    }

    return resolved;
    }
};

// Constants for message
SingleFireIR.Constants = {
  IS_BACKGROUND: 0,
  IS_HEAT: 1,
  IS_UNKNOWN: 255,
}

module.exports = SingleFireIR;
