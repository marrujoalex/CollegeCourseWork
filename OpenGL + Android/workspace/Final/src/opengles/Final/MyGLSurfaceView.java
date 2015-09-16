package opengles.Final;

//import
import android.content.Context;
import android.util.AttributeSet;
import android.opengl.GLSurfaceView;

public class MyGLSurfaceView extends GLSurfaceView {

public MyGLSurfaceView(Context context) {
    super(context);

}

public MyGLSurfaceView(Context context, AttributeSet attribs) {
    super(context, attribs);

}

@Override
public void onPause(){
    super.onPause();
}

@Override
public void onResume(){
    super.onResume();
}

}