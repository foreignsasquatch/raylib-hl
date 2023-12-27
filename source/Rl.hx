@:struct
@:structInit
class Color {
    public var r:Int;
    public var g:Int;
    public var b:Int;
    public var a:Int;
}

@:hlNative("raylib")
extern class Rl {
    // Window related functions
    static function initWindow(width:Int, height:Int, title:String):Void;
    static function closeWindow():Void;
    static function windowShouldClose():Bool;

    // Drawing-related functions
    static function beginDrawing():Void;
    static function endDrawing():Void;
    static function clearBackground(c:Color):Void;
}