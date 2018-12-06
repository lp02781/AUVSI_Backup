# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from kocheng/debug_mission.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class debug_mission(genpy.Message):
  _md5sum = "5ca02c94f587bbdb18e5bb5621c35260"
  _type = "kocheng/debug_mission"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """int16 setpoint
int16 state
int16 effort
float32 longitude
float32 latitude
"""
  __slots__ = ['setpoint','state','effort','longitude','latitude']
  _slot_types = ['int16','int16','int16','float32','float32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       setpoint,state,effort,longitude,latitude

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(debug_mission, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.setpoint is None:
        self.setpoint = 0
      if self.state is None:
        self.state = 0
      if self.effort is None:
        self.effort = 0
      if self.longitude is None:
        self.longitude = 0.
      if self.latitude is None:
        self.latitude = 0.
    else:
      self.setpoint = 0
      self.state = 0
      self.effort = 0
      self.longitude = 0.
      self.latitude = 0.

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
      buff.write(_get_struct_3h2f().pack(_x.setpoint, _x.state, _x.effort, _x.longitude, _x.latitude))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 14
      (_x.setpoint, _x.state, _x.effort, _x.longitude, _x.latitude,) = _get_struct_3h2f().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_3h2f().pack(_x.setpoint, _x.state, _x.effort, _x.longitude, _x.latitude))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 14
      (_x.setpoint, _x.state, _x.effort, _x.longitude, _x.latitude,) = _get_struct_3h2f().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_3h2f = None
def _get_struct_3h2f():
    global _struct_3h2f
    if _struct_3h2f is None:
        _struct_3h2f = struct.Struct("<3h2f")
    return _struct_3h2f