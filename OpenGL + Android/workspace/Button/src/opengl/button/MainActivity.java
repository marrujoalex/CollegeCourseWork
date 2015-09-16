package opengl.button;

import android.view.View.OnClickListener;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Button;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import opengl.button.R;
import android.app.Activity;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends Activity {
  Button imageButton;
  Button imageButton2;
  Bitmap bitmap;
  Bitmap bitmap2;
  ImageView image;
  TextView message;

  @Override
  public void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    setContentView(R.layout.activity_main);
    bitmap = BitmapFactory.decodeResource(this.getResources(), R.drawable.picture);
    bitmap2 = BitmapFactory.decodeResource(this.getResources(), R.drawable.picture2);
    addListenerOnButton();
  }
  //define Listeners
  public void addListenerOnButton() {
    imageButton = (Button) findViewById(R.id.imageButton1);
    imageButton2 = (Button) findViewById(R.id.imageButton2);

    imageButton.setOnClickListener(new OnClickListener() {
      @Override
      public void onClick(View view) {
       message = (TextView) findViewById(R.id.message);
       image = (ImageView) findViewById(R.id.carimage);
       message.setText("Image A");
       image.setImageBitmap(bitmap);
      }
    });

    imageButton2.setOnClickListener(new OnClickListener() {
      @Override
      public void onClick(View view) {
        message = (TextView) findViewById(R.id.message);
        image = (ImageView) findViewById(R.id.carimage);
        message.setText("Image B");
        image.setImageBitmap(bitmap2);
      }
    });
  }
}