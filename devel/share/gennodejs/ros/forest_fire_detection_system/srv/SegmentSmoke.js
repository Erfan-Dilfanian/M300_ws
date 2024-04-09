// Auto-generated. Do not edit!

// (in-package forest_fire_detection_system.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class SegmentSmokeRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.timeOut = null;
    }
    else {
      if (initObj.hasOwnProperty('timeOut')) {
        this.timeOut = initObj.timeOut
      }
      else {
        this.timeOut = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SegmentSmokeRequest
    // Serialize message field [timeOut]
    bufferOffset = _serializer.float32(obj.timeOut, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SegmentSmokeRequest
    let len;
    let data = new SegmentSmokeRequest(null);
    // Deserialize message field [timeOut]
    data.timeOut = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'forest_fire_detection_system/SegmentSmokeRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '27f74a0091364812ffb3f24bfa841d0a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # time to call the smoke segmentation, in seconds
    float32 timeOut
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SegmentSmokeRequest(null);
    if (msg.timeOut !== undefined) {
      resolved.timeOut = msg.timeOut;
    }
    else {
      resolved.timeOut = 0.0
    }

    return resolved;
    }
};

class SegmentSmokeResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.result = null;
    }
    else {
      if (initObj.hasOwnProperty('result')) {
        this.result = initObj.result
      }
      else {
        this.result = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SegmentSmokeResponse
    // Serialize message field [result]
    bufferOffset = _serializer.bool(obj.result, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SegmentSmokeResponse
    let len;
    let data = new SegmentSmokeResponse(null);
    // Deserialize message field [result]
    data.result = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'forest_fire_detection_system/SegmentSmokeResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'eb13ac1f1354ccecb7941ee8fa2192e8';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool result
    
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SegmentSmokeResponse(null);
    if (msg.result !== undefined) {
      resolved.result = msg.result;
    }
    else {
      resolved.result = false
    }

    return resolved;
    }
};

module.exports = {
  Request: SegmentSmokeRequest,
  Response: SegmentSmokeResponse,
  md5sum() { return '11478f9622703c748b49ba15c30aea4e'; },
  datatype() { return 'forest_fire_detection_system/SegmentSmoke'; }
};
