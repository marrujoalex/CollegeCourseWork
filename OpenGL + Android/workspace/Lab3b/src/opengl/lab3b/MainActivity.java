package opengl.lab3b;

import android.app.Activity;
import android.os.Bundle;
import android.content.Context;
import android.opengl.GLSurfaceView;
import android.view.MotionEvent;
//import android.view.Window;
//import android.view.WindowManager;
  
  public class MainActivity extends Activity {
    private GLSurfaceView mGLView;
        
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        //  Go fullscreen
        //  requestWindowFeature(Window.FEATURE_NO_TITLE);
        //  getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
        //  WindowManager.LayoutParams.FLAG_FULLSCREEN);
        //  Create a GLSurfaceView instance and set it
        //  as the ContentView for this Activity.
        mGLView = new CubeSurfaceView(this);
        //  mGLView = new GLSurfaceView(this);
        //  mGLView.setRenderer(new CubeRenderer());
        setContentView(mGLView);
    }
    
    @Override
    protected void onPause() {
        super.onPause();
        // The following call pauses the rendering thread.
        mGLView.onPause();
    }
    
    @Override
    protected void onResume() {
        super.onResume();
        // The following call resumes a paused rendering thread.
        mGLView.onResume();
    }
    
    class CubeSurfaceView extends GLSurfaceView {

    	    private final float TOUCH_SCALE_FACTOR = 180.0f / 320;
    	    private CubeRenderer renderer;
    	    private float previousX;
    	    private float previousY;
    	            
    	    public CubeSurfaceView(Context context){
    	      super(context);
    	      // set the renderer member
    	      renderer = new CubeRenderer( context );
    	      setRenderer(renderer);
    	            
    	      // Render the view only when there is a change
    	      setRenderMode(GLSurfaceView.RENDERMODE_WHEN_DIRTY);
    	    }
    	    @Override 
    	    public boolean onTouchEvent(MotionEvent e) {
    	      // MotionEvent reports input details from the touch screen
    	      // and other input controls. Here, we are only interested
    	      // in events where the touch position has changed.

    	      float x = e.getX();
    	      float y = e.getY();
    	            
    	      switch (e.getAction()) {
    	        case MotionEvent.ACTION_MOVE:
    	            
    	            float dx = x - previousX;
    	            float dy = y - previousY;
    	            
    	            // reverse direction of rotation above the mid-line
    	            if (y > getHeight() / 2) 
    	              dx = dx * -1 ;
    	                        
    	            // reverse direction of rotation to left of the mid-line
    	            if (x < getWidth() / 2) 
    	              dy = dy * -1 ;
    	                      
    	              renderer.angle += (dx + dy) * TOUCH_SCALE_FACTOR;
    	              requestRender();
    	          }

    	          previousX = x;
    	          previousY = y;
    	          return true;
    	    }
    }
}
