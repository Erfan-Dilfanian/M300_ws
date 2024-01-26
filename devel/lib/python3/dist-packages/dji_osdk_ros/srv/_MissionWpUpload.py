# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from dji_osdk_ros/MissionWpUploadRequest.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import dji_osdk_ros.msg

class MissionWpUploadRequest(genpy.Message):
  _md5sum = "412556517acb90aa4c3e713fbb867865"
  _type = "dji_osdk_ros/MissionWpUploadRequest"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """MissionWaypointTask waypoint_task   # see msg/MissionWaypointTask.msg

================================================================================
MSG: dji_osdk_ros/MissionWaypointTask
# constant for action_on_finish
uint8 FINISH_NO_ACTION       = 0  # no action
uint8 FINISH_RETURN_TO_HOME  = 1  # return to home
uint8 FINISH_AUTO_LANDING    = 2  # auto landing
uint8 FINISH_RETURN_TO_POINT = 3  # return to point 0
uint8 FINISH_NO_EXIT         = 4  # infinite mode， no exit

# constant for yaw_mode
uint8 YAW_MODE_AUTO     = 0       # auto mode (point to next waypoint)
uint8 YAW_MODE_LOCK     = 1       # lock as an initial value
uint8 YAW_MODE_RC       = 2       # controlled by RC
uint8 YAW_MODE_WAYPOINT = 3       # use waypoint's yaw(tgt_yaw)

# constant for trace_mode
uint8 TRACE_POINT       = 0       # point to point, after reaching the target waypoint hover, complete waypt action (if any), then fly to the next waypt
uint8 TRACE_COORDINATED = 1       # 1: Coordinated turn mode, smooth transition between waypts, no waypts task

# constants for action_on_rc_lost
uint8 ACTION_FREE       = 0       # exit waypoint and failsafe
uint8 ACTION_AUTO       = 1       # continue the waypoint

# constants for gimbal_pitch_mode
uint8 GIMBAL_PITCH_FREE = 0       # free mode, no control on gimbal
uint8 GIMBAL_PITCH_AUTO = 1       # auto mode, Smooth transition between waypoints on gimbal

float32 velocity_range    # Maximum speed joystick input(2~15m)
float32 idle_velocity     # Cruising Speed (without joystick input, no more than vel_cmd_range)
uint8 action_on_finish    # See constants above for possible actions
uint8 mission_exec_times  # 1: once ; 2: twice
uint8 yaw_mode            # see constants above for possible yaw modes
uint8 trace_mode          # see constants above for possible trace modes
uint8 action_on_rc_lost   # see constants above for possible actions
uint8 gimbal_pitch_mode   # see constants above for pissible gimbal modes
MissionWaypoint[] mission_waypoint  # a vector of waypoints


================================================================================
MSG: dji_osdk_ros/MissionWaypoint
float64 latitude          # degree
float64 longitude         # degree
float32 altitude          # relative altitude from takeoff point
float32 damping_distance  # Bend length (effective coordinated turn mode only)
int16 target_yaw          # Yaw (degree)
int16 target_gimbal_pitch # Gimbal pitch
uint8 turn_mode           # 0: clockwise, 1: counter-clockwise
uint8 has_action          # 0: no, 1: yes
uint16 action_time_limit
MissionWaypointAction waypoint_action

================================================================================
MSG: dji_osdk_ros/MissionWaypointAction
# action_repeat
# lower 4 bit: Total number of actions
# hight 4 bit: Total running times
uint8 action_repeat
uint8[16] command_list
uint16[16] command_parameter
"""
  __slots__ = ['waypoint_task']
  _slot_types = ['dji_osdk_ros/MissionWaypointTask']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       waypoint_task

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(MissionWpUploadRequest, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.waypoint_task is None:
        self.waypoint_task = dji_osdk_ros.msg.MissionWaypointTask()
    else:
      self.waypoint_task = dji_osdk_ros.msg.MissionWaypointTask()

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_2f6B().pack(_x.waypoint_task.velocity_range, _x.waypoint_task.idle_velocity, _x.waypoint_task.action_on_finish, _x.waypoint_task.mission_exec_times, _x.waypoint_task.yaw_mode, _x.waypoint_task.trace_mode, _x.waypoint_task.action_on_rc_lost, _x.waypoint_task.gimbal_pitch_mode))
      length = len(self.waypoint_task.mission_waypoint)
      buff.write(_struct_I.pack(length))
      for val1 in self.waypoint_task.mission_waypoint:
        _x = val1
        buff.write(_get_struct_2d2f2h2BH().pack(_x.latitude, _x.longitude, _x.altitude, _x.damping_distance, _x.target_yaw, _x.target_gimbal_pitch, _x.turn_mode, _x.has_action, _x.action_time_limit))
        _v1 = val1.waypoint_action
        _x = _v1.action_repeat
        buff.write(_get_struct_B().pack(_x))
        _x = _v1.command_list
        # - if encoded as a list instead, serialize as bytes instead of string
        if type(_x) in [list, tuple]:
          buff.write(_get_struct_16B().pack(*_x))
        else:
          buff.write(_get_struct_16s().pack(_x))
        buff.write(_get_struct_16H().pack(*_v1.command_parameter))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.waypoint_task is None:
        self.waypoint_task = dji_osdk_ros.msg.MissionWaypointTask()
      end = 0
      _x = self
      start = end
      end += 14
      (_x.waypoint_task.velocity_range, _x.waypoint_task.idle_velocity, _x.waypoint_task.action_on_finish, _x.waypoint_task.mission_exec_times, _x.waypoint_task.yaw_mode, _x.waypoint_task.trace_mode, _x.waypoint_task.action_on_rc_lost, _x.waypoint_task.gimbal_pitch_mode,) = _get_struct_2f6B().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.waypoint_task.mission_waypoint = []
      for i in range(0, length):
        val1 = dji_osdk_ros.msg.MissionWaypoint()
        _x = val1
        start = end
        end += 32
        (_x.latitude, _x.longitude, _x.altitude, _x.damping_distance, _x.target_yaw, _x.target_gimbal_pitch, _x.turn_mode, _x.has_action, _x.action_time_limit,) = _get_struct_2d2f2h2BH().unpack(str[start:end])
        _v2 = val1.waypoint_action
        start = end
        end += 1
        (_v2.action_repeat,) = _get_struct_B().unpack(str[start:end])
        start = end
        end += 16
        _v2.command_list = str[start:end]
        start = end
        end += 32
        _v2.command_parameter = _get_struct_16H().unpack(str[start:end])
        self.waypoint_task.mission_waypoint.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_2f6B().pack(_x.waypoint_task.velocity_range, _x.waypoint_task.idle_velocity, _x.waypoint_task.action_on_finish, _x.waypoint_task.mission_exec_times, _x.waypoint_task.yaw_mode, _x.waypoint_task.trace_mode, _x.waypoint_task.action_on_rc_lost, _x.waypoint_task.gimbal_pitch_mode))
      length = len(self.waypoint_task.mission_waypoint)
      buff.write(_struct_I.pack(length))
      for val1 in self.waypoint_task.mission_waypoint:
        _x = val1
        buff.write(_get_struct_2d2f2h2BH().pack(_x.latitude, _x.longitude, _x.altitude, _x.damping_distance, _x.target_yaw, _x.target_gimbal_pitch, _x.turn_mode, _x.has_action, _x.action_time_limit))
        _v3 = val1.waypoint_action
        _x = _v3.action_repeat
        buff.write(_get_struct_B().pack(_x))
        _x = _v3.command_list
        # - if encoded as a list instead, serialize as bytes instead of string
        if type(_x) in [list, tuple]:
          buff.write(_get_struct_16B().pack(*_x))
        else:
          buff.write(_get_struct_16s().pack(_x))
        buff.write(_v3.command_parameter.tostring())
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.waypoint_task is None:
        self.waypoint_task = dji_osdk_ros.msg.MissionWaypointTask()
      end = 0
      _x = self
      start = end
      end += 14
      (_x.waypoint_task.velocity_range, _x.waypoint_task.idle_velocity, _x.waypoint_task.action_on_finish, _x.waypoint_task.mission_exec_times, _x.waypoint_task.yaw_mode, _x.waypoint_task.trace_mode, _x.waypoint_task.action_on_rc_lost, _x.waypoint_task.gimbal_pitch_mode,) = _get_struct_2f6B().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.waypoint_task.mission_waypoint = []
      for i in range(0, length):
        val1 = dji_osdk_ros.msg.MissionWaypoint()
        _x = val1
        start = end
        end += 32
        (_x.latitude, _x.longitude, _x.altitude, _x.damping_distance, _x.target_yaw, _x.target_gimbal_pitch, _x.turn_mode, _x.has_action, _x.action_time_limit,) = _get_struct_2d2f2h2BH().unpack(str[start:end])
        _v4 = val1.waypoint_action
        start = end
        end += 1
        (_v4.action_repeat,) = _get_struct_B().unpack(str[start:end])
        start = end
        end += 16
        _v4.command_list = str[start:end]
        start = end
        end += 32
        _v4.command_parameter = numpy.frombuffer(str[start:end], dtype=numpy.uint16, count=16)
        self.waypoint_task.mission_waypoint.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_16B = None
def _get_struct_16B():
    global _struct_16B
    if _struct_16B is None:
        _struct_16B = struct.Struct("<16B")
    return _struct_16B
_struct_16H = None
def _get_struct_16H():
    global _struct_16H
    if _struct_16H is None:
        _struct_16H = struct.Struct("<16H")
    return _struct_16H
_struct_16s = None
def _get_struct_16s():
    global _struct_16s
    if _struct_16s is None:
        _struct_16s = struct.Struct("<16s")
    return _struct_16s
_struct_2d2f2h2BH = None
def _get_struct_2d2f2h2BH():
    global _struct_2d2f2h2BH
    if _struct_2d2f2h2BH is None:
        _struct_2d2f2h2BH = struct.Struct("<2d2f2h2BH")
    return _struct_2d2f2h2BH
_struct_2f6B = None
def _get_struct_2f6B():
    global _struct_2f6B
    if _struct_2f6B is None:
        _struct_2f6B = struct.Struct("<2f6B")
    return _struct_2f6B
_struct_B = None
def _get_struct_B():
    global _struct_B
    if _struct_B is None:
        _struct_B = struct.Struct("<B")
    return _struct_B
# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from dji_osdk_ros/MissionWpUploadResponse.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class MissionWpUploadResponse(genpy.Message):
  _md5sum = "f03b0bc279b265c40946c1011df83013"
  _type = "dji_osdk_ros/MissionWpUploadResponse"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """bool result
# for debugging usage
uint8 cmd_set
uint8 cmd_id
uint32 ack_data

"""
  __slots__ = ['result','cmd_set','cmd_id','ack_data']
  _slot_types = ['bool','uint8','uint8','uint32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       result,cmd_set,cmd_id,ack_data

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(MissionWpUploadResponse, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.result is None:
        self.result = False
      if self.cmd_set is None:
        self.cmd_set = 0
      if self.cmd_id is None:
        self.cmd_id = 0
      if self.ack_data is None:
        self.ack_data = 0
    else:
      self.result = False
      self.cmd_set = 0
      self.cmd_id = 0
      self.ack_data = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_3BI().pack(_x.result, _x.cmd_set, _x.cmd_id, _x.ack_data))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      _x = self
      start = end
      end += 7
      (_x.result, _x.cmd_set, _x.cmd_id, _x.ack_data,) = _get_struct_3BI().unpack(str[start:end])
      self.result = bool(self.result)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_3BI().pack(_x.result, _x.cmd_set, _x.cmd_id, _x.ack_data))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      _x = self
      start = end
      end += 7
      (_x.result, _x.cmd_set, _x.cmd_id, _x.ack_data,) = _get_struct_3BI().unpack(str[start:end])
      self.result = bool(self.result)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_3BI = None
def _get_struct_3BI():
    global _struct_3BI
    if _struct_3BI is None:
        _struct_3BI = struct.Struct("<3BI")
    return _struct_3BI
class MissionWpUpload(object):
  _type          = 'dji_osdk_ros/MissionWpUpload'
  _md5sum = 'e18bb47c4399b0ec1e363c0b0e75db0f'
  _request_class  = MissionWpUploadRequest
  _response_class = MissionWpUploadResponse
