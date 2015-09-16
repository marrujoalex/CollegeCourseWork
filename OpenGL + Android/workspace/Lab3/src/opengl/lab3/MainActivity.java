package opengl.lab3;

import android.support.v7.app.ActionBarActivity;
import android.support.v7.app.ActionBar;
import android.support.v4.app.Fragment;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.os.Build;
import android.view.Window;
import android.view.WindowManager;
import android.opengl.GLSurfaceView;

public class MainActivity extends ActionBarActivity {
	private GLSurfaceView mGLSurfaceView;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        requestWindowFeature(Window.FEATURE_NO_TITLE);
        setContentView(R.layout.activity_main);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
        	      WindowManager.LayoutParams.FLAG_FULLSCREEN);

        	      // Create our Preview view and set it as the content of our
        	      // Activity
        mGLSurfaceView = new GLSurfaceView(this);
        TetrahedronRenderer renderer = new TetrahedronRenderer();
        mGLSurfaceView.setRenderer(renderer);
        setContentView(mGLSurfaceView);
        if (savedInstanceState == null) {
            getSupportFragmentManager().beginTransaction()
                    .add(R.id.container, new PlaceholderFragment())
                    .commit();
        }
    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();
        if (id == R.id.action_settings) {
            return true;
        }
        return super.onOptionsItemSelected(item);
    }

    
    
    /**
     * A placeholder fragment containing a simple view.
     */
    public static class PlaceholderFragment extends Fragment {

        public PlaceholderFragment() {
        }

        @Override
        public View onCreateView(LayoutInflater inflater, ViewGroup container,
                Bundle savedInstanceState) {
            View rootView = inflater.inflate(R.layout.fragment_main, container, false);
            return rootView;
        }
    }
    @Override
    protected void onResume() {
      // Ideally a game should implement onResume() and onPause()
      // to take appropriate action when the activity looses focus
      super.onResume();
      mGLSurfaceView.onResume();
    }
    
    @Override
    protected void onPause() {
      // Ideally a game should implement onResume() and onPause()
      // to take appropriate action when the activity looses focus
      super.onPause();
      mGLSurfaceView.onPause();
    }
}
