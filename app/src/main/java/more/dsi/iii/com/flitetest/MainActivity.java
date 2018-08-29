package more.dsi.iii.com.flitetest;

import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends ActionBarActivity
{
    private EditText mEdit = null;
    private Button mButton = null;
    
    // Used to load the 'native-lib' library on application startup.
    static
    {
        System.loadLibrary("native-lib");
    }
    
    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mEdit = (EditText) findViewById(R.id.editText);
        mButton = (Button) findViewById(R.id.button);
        mButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                new Thread(new Runnable()
                {
                    @Override
                    public void run()
                    {
                        Log.i("DEBUG_JAVA",mEdit.getText().toString());
                        convertToLabels(mEdit.getText().toString());
                    }
                }).start();
            }
        });
        
    }
    
    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    
    
    public native void convertToLabels(String text);
}
