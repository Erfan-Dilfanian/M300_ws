# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from dji_osdk_ros/WaypointV2IntervalTrigger.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class WaypointV2IntervalTrigger(genpy.Message):
  _md5sum = "9a737930d3da7d390475e0a354220c42"
  _type = "dji_osdk_ros/WaypointV2IntervalTrigger"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """#constant for actionIntervalType
uint8 DJIWaypointV2ActionIntervalTypeTime     = 1  # The action will be repeated after a particular period of time.
uint8 DJIWaypointV2ActionIntervalTypeDistance = 2  # The action will be repeated after a particular distance.
uint8 DJIWaypointV2ActionIntervalTypeUnknown  = 255 # Unknown action trigger type.

uint16 startIndex # It determines the index of the waypoint at which the trigger starts.
# If the  ``DJIWaypointV2Action_DJIWaypointV2IntervalTriggerParam_actionIntervalType``
# is ``DJIWaypointV2MissionV2_DJIWaypointV2TriggerAssociatedTimingType_Time``
# The time interval in seconds when two action are executed as the aircraft moves
# from the current waypoint to the next waypoint.
# If the ``DJIWaypointV2Action_DJIWaypointV2IntervalTriggerParam_actionIntervalType`` is
# ``DJIWaypointV2MissionV2_DJIWaypointV2TriggerAssociatedTimingType_Distance``
# The distance interval in meters when two action are executed as the aircraft moves
# from the current waypoint to the next waypoint.
uint16 interval
uint8 actionIntervalType # The type of interval trigger.
                         # See ``DJIWaypointV2MissionV2_DJIWaypointV2ActionIntervalType``."""
  # Pseudo-constants
  DJIWaypointV2ActionIntervalTypeTime = 1
  DJIWaypointV2ActionIntervalTypeDistance = 2
  DJIWaypointV2ActionIntervalTypeUnknown = 255

  __slots__ = ['startIndex','interval','actionIntervalType']
  _slot_types = ['uint16','uint16','uint8']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       startIndex,interval,actionIntervalType

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(WaypointV2IntervalTrigger, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.startIndex is None:
        self.startIndex = 0
      if self.interval is None:
        self.interval = 0
      if self.actionIntervalType is None:
        self.actionIntervalType = 0
    else:
      self.startIndex = 0
      self.interval = 0
      self.actionIntervalType = 0

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
      buff.write(_get_struct_2HB().pack(_x.startIndex, _x.interval, _x.actionIntervalType))
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
      end += 5
      (_x.startIndex, _x.interval, _x.actionIntervalType,) = _get_struct_2HB().unpack(str[start:end])
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
      buff.write(_get_struct_2HB().pack(_x.startIndex, _x.interval, _x.actionIntervalType))
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
      end += 5
      (_x.startIndex, _x.interval, _x.actionIntervalType,) = _get_struct_2HB().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_2HB = None
def _get_struct_2HB():
    global _struct_2HB
    if _struct_2HB is None:
        _struct_2HB = struct.Struct("<2HB")
    return _struct_2HB
