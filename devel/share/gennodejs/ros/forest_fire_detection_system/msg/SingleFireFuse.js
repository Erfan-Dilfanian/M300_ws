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

class SingleFireFuse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.ir_img_width = null;
      this.ir_img_height = null;
      this.rgb_img_width = null;
      this.rgb_img_height = null;
      this.target_type = null;
      this.focuse_mode = null;
      this.ir_img_x = null;
      this.ir_img_y = null;
      this.rgb_img_x = null;
      this.rgb_img_y = null;
      this.scale = null;
      this.offset_x = null;
      this.offset_y = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('ir_img_width')) {
        this.ir_img_width = initObj.ir_img_width
      }
      else {
        this.ir_img_width = 0;
      }
      if (initObj.hasOwnProperty('ir_img_height')) {
        this.ir_img_height = initObj.ir_img_height
      }
      else {
        this.ir_img_height = 0;
      }
      if (initObj.hasOwnProperty('rgb_img_width')) {
        this.rgb_img_width = initObj.rgb_img_width
      }
      else {
        this.rgb_img_width = 0;
      }
      if (initObj.hasOwnProperty('rgb_img_height')) {
        this.rgb_img_height = initObj.rgb_img_height
      }
      else {
        this.rgb_img_height = 0;
      }
      if (initObj.hasOwnProperty('target_type')) {
        this.target_type = initObj.target_type
      }
      else {
        this.target_type = 0;
      }
      if (initObj.hasOwnProperty('focuse_mode')) {
        this.focuse_mode = initObj.focuse_mode
      }
      else {
        this.focuse_mode = 0;
      }
      if (initObj.hasOwnProperty('ir_img_x')) {
        this.ir_img_x = initObj.ir_img_x
      }
      else {
        this.ir_img_x = 0.0;
      }
      if (initObj.hasOwnProperty('ir_img_y')) {
        this.ir_img_y = initObj.ir_img_y
      }
      else {
        this.ir_img_y = 0.0;
      }
      if (initObj.hasOwnProperty('rgb_img_x')) {
        this.rgb_img_x = initObj.rgb_img_x
      }
      else {
        this.rgb_img_x = 0.0;
      }
      if (initObj.hasOwnProperty('rgb_img_y')) {
        this.rgb_img_y = initObj.rgb_img_y
      }
      else {
        this.rgb_img_y = 0.0;
      }
      if (initObj.hasOwnProperty('scale')) {
        this.scale = initObj.scale
      }
      else {
        this.scale = 0.0;
      }
      if (initObj.hasOwnProperty('offset_x')) {
        this.offset_x = initObj.offset_x
      }
      else {
        this.offset_x = 0.0;
      }
      if (initObj.hasOwnProperty('offset_y')) {
        this.offset_y = initObj.offset_y
      }
      else {
        this.offset_y = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SingleFireFuse
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [ir_img_width]
    bufferOffset = _serializer.uint16(obj.ir_img_width, buffer, bufferOffset);
    // Serialize message field [ir_img_height]
    bufferOffset = _serializer.uint16(obj.ir_img_height, buffer, bufferOffset);
    // Serialize message field [rgb_img_width]
    bufferOffset = _serializer.uint16(obj.rgb_img_width, buffer, bufferOffset);
    // Serialize message field [rgb_img_height]
    bufferOffset = _serializer.uint16(obj.rgb_img_height, buffer, bufferOffset);
    // Serialize message field [target_type]
    bufferOffset = _serializer.uint8(obj.target_type, buffer, bufferOffset);
    // Serialize message field [focuse_mode]
    bufferOffset = _serializer.uint8(obj.focuse_mode, buffer, bufferOffset);
    // Serialize message field [ir_img_x]
    bufferOffset = _serializer.float32(obj.ir_img_x, buffer, bufferOffset);
    // Serialize message field [ir_img_y]
    bufferOffset = _serializer.float32(obj.ir_img_y, buffer, bufferOffset);
    // Serialize message field [rgb_img_x]
    bufferOffset = _serializer.float32(obj.rgb_img_x, buffer, bufferOffset);
    // Serialize message field [rgb_img_y]
    bufferOffset = _serializer.float32(obj.rgb_img_y, buffer, bufferOffset);
    // Serialize message field [scale]
    bufferOffset = _serializer.float32(obj.scale, buffer, bufferOffset);
    // Serialize message field [offset_x]
    bufferOffset = _serializer.float32(obj.offset_x, buffer, bufferOffset);
    // Serialize message field [offset_y]
    bufferOffset = _serializer.float32(obj.offset_y, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SingleFireFuse
    let len;
    let data = new SingleFireFuse(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [ir_img_width]
    data.ir_img_width = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [ir_img_height]
    data.ir_img_height = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [rgb_img_width]
    data.rgb_img_width = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [rgb_img_height]
    data.rgb_img_height = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [target_type]
    data.target_type = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [focuse_mode]
    data.focuse_mode = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [ir_img_x]
    data.ir_img_x = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [ir_img_y]
    data.ir_img_y = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [rgb_img_x]
    data.rgb_img_x = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [rgb_img_y]
    data.rgb_img_y = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [scale]
    data.scale = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [offset_x]
    data.offset_x = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [offset_y]
    data.offset_y = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 38;
  }

  static datatype() {
    // Returns string type for a message object
    return 'forest_fire_detection_system/SingleFireFuse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '5acee9e57a872fd936b9b0d95ff37894';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header header
    
    # image detecting on info
    uint16 ir_img_width
    uint16 ir_img_height
    uint16 rgb_img_width
    uint16 rgb_img_height
    
    # target type
    uint8 IS_BACKGROUND = 0
    uint8 IS_TARGET = 1
    uint8 IS_UNKNOWN = 255
    
    uint8 target_type
    
    # focuse mode
    uint8 USE_NONE = 0
    uint8 USE_IR  = 1
    uint8 USE_RGB  = 2
    
    uint8 focuse_mode
    
    # the x and y pos (sub-pixel) of the single fire, opencv style coordinates
    float32 ir_img_x
    float32 ir_img_y
    float32 rgb_img_x
    float32 rgb_img_y
    
    # translation(ir->rgb)
    float32 scale
    float32 offset_x
    float32 offset_y
    
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
    const resolved = new SingleFireFuse(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.ir_img_width !== undefined) {
      resolved.ir_img_width = msg.ir_img_width;
    }
    else {
      resolved.ir_img_width = 0
    }

    if (msg.ir_img_height !== undefined) {
      resolved.ir_img_height = msg.ir_img_height;
    }
    else {
      resolved.ir_img_height = 0
    }

    if (msg.rgb_img_width !== undefined) {
      resolved.rgb_img_width = msg.rgb_img_width;
    }
    else {
      resolved.rgb_img_width = 0
    }

    if (msg.rgb_img_height !== undefined) {
      resolved.rgb_img_height = msg.rgb_img_height;
    }
    else {
      resolved.rgb_img_height = 0
    }

    if (msg.target_type !== undefined) {
      resolved.target_type = msg.target_type;
    }
    else {
      resolved.target_type = 0
    }

    if (msg.focuse_mode !== undefined) {
      resolved.focuse_mode = msg.focuse_mode;
    }
    else {
      resolved.focuse_mode = 0
    }

    if (msg.ir_img_x !== undefined) {
      resolved.ir_img_x = msg.ir_img_x;
    }
    else {
      resolved.ir_img_x = 0.0
    }

    if (msg.ir_img_y !== undefined) {
      resolved.ir_img_y = msg.ir_img_y;
    }
    else {
      resolved.ir_img_y = 0.0
    }

    if (msg.rgb_img_x !== undefined) {
      resolved.rgb_img_x = msg.rgb_img_x;
    }
    else {
      resolved.rgb_img_x = 0.0
    }

    if (msg.rgb_img_y !== undefined) {
      resolved.rgb_img_y = msg.rgb_img_y;
    }
    else {
      resolved.rgb_img_y = 0.0
    }

    if (msg.scale !== undefined) {
      resolved.scale = msg.scale;
    }
    else {
      resolved.scale = 0.0
    }

    if (msg.offset_x !== undefined) {
      resolved.offset_x = msg.offset_x;
    }
    else {
      resolved.offset_x = 0.0
    }

    if (msg.offset_y !== undefined) {
      resolved.offset_y = msg.offset_y;
    }
    else {
      resolved.offset_y = 0.0
    }

    return resolved;
    }
};

// Constants for message
SingleFireFuse.Constants = {
  IS_BACKGROUND: 0,
  IS_TARGET: 1,
  IS_UNKNOWN: 255,
  USE_NONE: 0,
  USE_IR: 1,
  USE_RGB: 2,
}

module.exports = SingleFireFuse;
